using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Web;
using System.Web.Mvc;
using AutoMapper;
using Lernify.BusinessLogic.Interfaces;
using Lernify.Domain.Entities.Course;
using Lernify.Domain.Entities.Enroll;
using Lernify.Domain.Entities.Teacher;
using Lernify.Helpers;
using Lernify.Web.Filters;
using Lernify.Web.Models;

namespace Lernify.Web.Controllers
{
    public class CourseController : BaseController
    {
         private readonly ICourse _courseBL;
         private readonly IEnrollCourses _cEnrollingBL;

          public CourseController()
         {
              var bl = new BusinessLogic.BusinessLogic();
              _courseBL = bl.GetCourseBL();
              _cEnrollingBL = bl.GetEnrollCoursesBl();
         }
          public ActionResult Index()
          {
               SessionStatus();
               IMapper mappeer = new MapperConfiguration(cfg =>
                   cfg.CreateMap<Course, CourseModel>()).CreateMapper();
               var course = mappeer.Map<List<CourseModel>>(_courseBL.GetList());
               return View(course);
          }

          [Authenticated]
          public ActionResult Create()
          {
               SessionStatus();
               return View();
          }

          [Authenticated]
          [HttpPost]
          public ActionResult Create(CourseModel course)
          {
               SessionStatus();
               if (ModelState.IsValid)
               {
                    IMapper mappeer = new MapperConfiguration(cfg =>
                        cfg.CreateMap<CourseModel, Course>()).CreateMapper();
                    var data = mappeer.Map<Course>(course);

                    var newPhoto = _courseBL.Add(data);
                    if (newPhoto.Status)
                    {
                         return RedirectToAction("Index");
                    }
                    else
                    {
                         ModelState.AddModelError("", newPhoto.StatusMsg);
                         return View();
                    }
               }
               return View();
          }


          // GET: Course/Details/1
          [AdminMod]
          public ActionResult Details(int id)
          {
               SessionStatus();
               var photo = _courseBL.GetbyId(id);
               if (photo != null)
               {
                    var config = new MapperConfiguration(cfg => cfg.CreateMap<Course, CourseModel>());
                    IMapper mapper = config.CreateMapper();
                    var data = mapper.Map<CourseModel>(photo);
                    return View(data);
               }

               return View("NotFound");
          }
          [Authenticated]
          // GET: Course/CourseDetail/1
          public ActionResult CourseDetails(int id)
          {
               SessionStatus();
               var empDetails = _courseBL.GetbyId(id);
               if (empDetails != null)
               {
                    var config = new MapperConfiguration(cfg => cfg.CreateMap<Course, CourseModel>());
                    IMapper mapper = config.CreateMapper();
                    var data = mapper.Map<CourseModel>(empDetails);
                    return View(data);
               }

               return View("NotFound");
          }

               [AdminMod]
          public ActionResult Edit(int id)
          {
               SessionStatus();
               var photo = _courseBL.GetbyId(id);
               if (photo != null)
               {
                    var config = new MapperConfiguration(cfg => cfg.CreateMap<Course, CourseModel>());
                    IMapper mapper = config.CreateMapper();
                    var data = mapper.Map<CourseModel>(photo);
                    return View(data);
               }

               return View("NotFound");
          }

               [AdminMod]
          [HttpPost]
          public ActionResult Edit(CourseModel course)
          {
               SessionStatus();
               if (ModelState.IsValid)
               {
                    IMapper mappeer = new MapperConfiguration(cfg =>
                        cfg.CreateMap<CourseModel, Course>()).CreateMapper();
                    var data = mappeer.Map<Course>(course);

                    var uPhoto = _courseBL.Edit(data);
                    if (uPhoto.Status)
                    {
                         return RedirectToAction("Index");
                    }
                    else
                    {
                         ModelState.AddModelError("", uPhoto.StatusMsg);
                         return View();
                    }
               }
               return View();
          }
          // GET: Course/Delete/1
               [AdminMod]
          public ActionResult Delete(int id)
          {
               SessionStatus();
               var photo = _courseBL.GetbyId(id);
               if (photo != null)
               {
                    var config = new MapperConfiguration(cfg => cfg.CreateMap<Course, CourseModel>());
                    IMapper mapper = config.CreateMapper();
                    var data = mapper.Map<CourseModel>(photo);
                    return View(data);
               }

               return View("NotFound");
          }

               [AdminMod]
          [HttpPost, ActionName("Delete")]
          public ActionResult DeleteConfirmed(int id)
          {
               var empDetails = _courseBL.GetbyId(id);
               if (empDetails == null) return View("NotFound");
               _courseBL.Delete(id);
               return RedirectToAction("Index");
          }

          //GET: COurse/Enroll/1
          public ActionResult EnrollCourse(int id)
          {
               SessionStatus();
               if ((string)System.Web.HttpContext.Current.Session["LoginStatus"] != "login")
               {
                    return RedirectToAction("Index", "Login");
               }

               var evDetails = _courseBL.GetbyId(id);
               if (evDetails != null)
               {
                    ViewBag.Event = evDetails;
                    var enroll = new EnrollModel
                    {
                         UserId = ViewBag.CurrentUser.Id,
                         FullName = ViewBag.CurrentUser.Username,
                         CourseName = evDetails.Name,
                         Email = ViewBag.CurrentUser.Email,
                         
                         CourseId = evDetails.Id,
                    };
                    return View(enroll);
               }

               return View("NotFound");
          }

          [Authenticated]
          [HttpPost]
          public ActionResult EnrollCourse(EnrollModel enroll)
          {
               SessionStatus();
               var courseDetail = _courseBL.GetbyId(enroll.CourseId);
               ViewBag.Event = courseDetail;

               if (ModelState.IsValid)
               {
                    if (courseDetail == null) return View("NotFound");

                    IMapper mapper = MappingHelper.Configure<EnrollModel, Enroll>();
                    var enrollModel = mapper.Map<Enroll>(enroll);

                    var bookingResult = _cEnrollingBL.Book(enroll.CourseId, enrollModel);

                    if (bookingResult.Status)
                    {
                         return RedirectToAction("Index");
                    }

                    ModelState.AddModelError("", bookingResult.StatusMsg);
                    return View(enroll);
               }
               return View(enroll);
          }
     }
}





