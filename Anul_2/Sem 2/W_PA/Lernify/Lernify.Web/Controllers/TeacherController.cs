using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using AutoMapper;
using Lernify.BusinessLogic.Interfaces;
using Lernify.Domain.Entities.Teacher;
using Lernify.Web.Filters;
using Lernify.Web.Models;

namespace Lernify.Web.Controllers
{
     public class TeacherController : BaseController
     {


          private readonly ITeacher _teacherBL;

          public TeacherController()
          {
               var bl = new BusinessLogic.BusinessLogic();
               _teacherBL = bl.GetTeacherBL();

          }

          //GET: Teacher
          public ActionResult Index()
          {
               SessionStatus();
               var config = new MapperConfiguration(cfg => { cfg.CreateMap<Teacher, TeacherModel>(); });
               IMapper mapper = config.CreateMapper();

               var staff = mapper.Map<List<TeacherModel>>(_teacherBL.GetTeacher());
               return View(staff);
          }

          //GET: Teacher/Create
          [AdminMod]
          public ActionResult Create()
          {
               SessionStatus();
               return View();
          }

          [AdminMod]
          [HttpPost]
          public ActionResult Create (Teacher teacher)
          {
               SessionStatus();
               if (ModelState.IsValid)
               {
                    var config = new MapperConfiguration(cfg => cfg.CreateMap<TeacherModel, Teacher>());
                    IMapper mapper = config.CreateMapper();
                    var data = mapper.Map<Teacher>(teacher);

                    var employeeAdded = _teacherBL.AddTeacher(data);
                    if (employeeAdded.Status)
                    {
                         return RedirectToAction("Index");
                    }
                    else
                    {
                         ModelState.AddModelError("", employeeAdded.StatusMsg);
                         return View();
                    }
               }

               return View();
          }

          // GET: Teacher/Details/1
          [AdminMod]
          public ActionResult Details(int id)
          {
               SessionStatus();
               var empDetails = _teacherBL.GetTeacherById(id);
               if (empDetails != null)
               {
                    var config = new MapperConfiguration(cfg => cfg.CreateMap<Teacher, TeacherModel>());
                    IMapper mapper = config.CreateMapper();
                    var data = mapper.Map<TeacherModel>(empDetails);
                    return View(data);
               }

               return View("NotFound");
          }

          [Authenticated]
          // GET: Teacher/TeacherDetail/1
          public ActionResult TeacherDetails(int id)
          {
               SessionStatus();
               var empDetails = _teacherBL.GetTeacherById(id);
               if (empDetails != null)
               {
                    var config = new MapperConfiguration(cfg => cfg.CreateMap<Teacher, TeacherModel>());
                    IMapper mapper = config.CreateMapper();
                    var data = mapper.Map<TeacherModel>(empDetails);
                    return View(data);
               }

               return View("NotFound");
          }

          // GET: Teacher/Edit/1
          [AdminMod]
          public ActionResult Edit(int id)
          {
               SessionStatus();
               var empDetails = _teacherBL.GetTeacherById(id);
               if (empDetails != null)
               {
                    var config = new MapperConfiguration(cfg => cfg.CreateMap<Teacher, TeacherModel>());
                    IMapper mapper = config.CreateMapper();
                    var data = mapper.Map<TeacherModel>(empDetails);
                    return View(data);
               }

               return View("NotFound");
          }
          [AdminMod]
          [HttpPost]
          public ActionResult Edit(Teacher teacher)
          {
               SessionStatus();
               if (ModelState.IsValid)
               {
                    var config = new MapperConfiguration(cfg => cfg.CreateMap<TeacherModel, Teacher>());
                    IMapper mapper = config.CreateMapper();
                    var data = mapper.Map<Teacher>(teacher);

                    var employeeAdded = _teacherBL.UpdateTeacher(data);
                    if (employeeAdded.Status)
                    {
                         return RedirectToAction("Index");
                    }
                    else
                    {
                         ModelState.AddModelError("", employeeAdded.StatusMsg);
                         return View();
                    }
               }

               return View();
          }

          // GET: Teacher/Delete/1
          [AdminMod]
          public ActionResult Delete(int id)
          {
               SessionStatus();
               var empDetails = _teacherBL.GetTeacherById(id);
               if (empDetails != null)
               {
                    var config = new MapperConfiguration(cfg => cfg.CreateMap<Teacher, TeacherModel>());
                    IMapper mapper = config.CreateMapper();
                    var data = mapper.Map<TeacherModel>(empDetails);
                    return View(data);
               }

               return View("NotFound");
          }

          [AdminMod]
          [HttpPost, ActionName("Delete")]
          public ActionResult DeleteConfirmed(int id)
          {
               var empDetails = _teacherBL.GetTeacherById(id);
               if (empDetails == null) return View("NotFound");
               _teacherBL.DeleteTeacher(id);
               return RedirectToAction("Index");
          }

     }
}