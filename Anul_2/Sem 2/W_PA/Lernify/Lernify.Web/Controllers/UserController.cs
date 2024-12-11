using AutoMapper;
using Lernify.Web.Extension;
using Lernify.Web.Filters;
using Lernify.Web.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Lernify.Domain.Entities.User;
using System.Net.Sockets;
using Lernify.BusinessLogic.Interfaces;
using Lernify.Domain.Entities.Enroll;
using Lernify.Helpers;

namespace Lernify.Web.Controllers
{
     [Authenticated]
     public class UserController : BaseController

     {


          private readonly IEnrollCourses _enrollBL;
          public UserController()
          {
               var bl = new BusinessLogic.BusinessLogic();
               _enrollBL = bl.GetEnrollCoursesBl();
          }

          // GET: User
          public ActionResult Index()
          {
               SessionStatus();
               if ((string)System.Web.HttpContext.Current.Session["LoginStatus"] != "login")
               {
                    return RedirectToAction("Index", "Login");
               }

               var user = System.Web.HttpContext.Current.GetMySessionObject();

               var config = new MapperConfiguration(cfg =>
               {
                    cfg.CreateMap<UserMinimal, UserData>();
               });
               IMapper mapper = config.CreateMapper();
               var data = mapper.Map<UserData>(user);

               return View(data);
          }

          public ActionResult Logout()
          {
               Session.Abandon();
               System.Web.HttpContext.Current.Session.Clear();
               if (ControllerContext.HttpContext.Request.Cookies.AllKeys.Contains("X-KEY"))
               {
                    var cookie = ControllerContext.HttpContext.Request.Cookies["X-KEY"];
                    if (cookie != null)
                    {
                         cookie.Expires = DateTime.Now.AddDays(-1);
                         ControllerContext.HttpContext.Response.Cookies.Add(cookie);
                    }
               }
               System.Web.HttpContext.Current.Session["LoginStatus"] = "logout";
               return RedirectToAction("Index", "Home");
          }
          [Authenticated]
          public ActionResult EnrolledCourses(int userId, int? eventId)
          {
               SessionStatus();
               IMapper mapper = MappingHelper.Configure<Enroll, EnrollModel>();

               var enrolling = mapper.Map<List<EnrollModel>>(_enrollBL.GetByUserId(userId, eventId));
               return View(enrolling);

          }

          [Authenticated]
          public ActionResult CancelEnrollment(int id)
          {
               var booking = _enrollBL.GetById(id);
               if (booking == null) return View("NotFound");
               _enrollBL.Delete(id);
               var user = System.Web.HttpContext.Current.GetMySessionObject();

               return RedirectToAction("EnrolledCourses", new { userid = user.Id });
          }


     }
}