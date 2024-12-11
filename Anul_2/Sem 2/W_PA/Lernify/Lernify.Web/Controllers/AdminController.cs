using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Web;
using System.Web.Mvc;
using AutoMapper;
using Lernify.BusinessLogic.Interfaces;
using Lernify.Domain.Entities.Enroll;
using Lernify.Domain.Entities.User;
using Lernify.Helpers;
using Lernify.Web.Filters;
using Lernify.Web.Models;

namespace Lernify.Web.Controllers
{
     [AdminMod]
     public class AdminController : BaseController
     {
          private readonly IUser _userBL;
          private readonly IEnrollCourses _enrollBL;
          public AdminController()
          {
               var bl = new BusinessLogic.BusinessLogic();
               _userBL = bl.GetUserBL();
               _enrollBL = bl.GetEnrollCoursesBl();
          }
          // GET: Admin
          public ActionResult Index()
          {
               SessionStatus();
               var configure = new MapperConfiguration(cfg =>
                    cfg.CreateMap<UserMinimal, UserData>());
               IMapper mapper = configure.CreateMapper();

               var users = mapper.Map<List<UserData>>(_userBL.GetList());
               return View(users);
          }

          [HttpPost]
          public ActionResult Delete(int id)
          {
               var user = _userBL.GetById(id);
               if (user == null) return View("NotFound");
               _userBL.Delete(id);
               return RedirectToAction("Index");
          }
          public ActionResult Enrolled(string searchCriteria)
          {
               SessionStatus();
               IMapper mapper = MappingHelper.Configure<Enroll, EnrollModel>();

               var tickets = mapper.Map<List<EnrollModel>>(_enrollBL.GetEnroledCourseList(searchCriteria));
               return View(tickets);
          }

          public ActionResult DeleteTicketBooking(int id)
          {
               var ticket = _enrollBL.GetById(id);
               if (ticket == null) return View("NotFound");
               _enrollBL.Delete(id);
               return RedirectToAction("Enrolled");
          }
     }
}