using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Data.Entity.Migrations;
using System.Linq;
using AutoMapper;
using Lernify.BusinessLogic.DBModel;
using Lernify.Domain.Entities.Course;
using Lernify.Domain.Entities.Enroll;
using Lernify.Domain.Entities.Teacher;
using Lernify.Domain.Entities.User;
using Lernify.Helpers;

namespace Lernify.BusinessLogic.Core
{
     //Get List
     public class ProductApi
     {
          internal List<Course> GetCourseList()
          {
               List<CDbTable> context;

               var mapper = new MapperConfiguration(cfg => cfg.CreateMap<CDbTable, Course>()).CreateMapper();
               using (var db = new CourseContext())
               {
                    context = db.Courses.ToList();
               }
               return mapper.Map<List<Course>>(context);
          }

          internal List<Teacher> GetTeacherList()
          {
               List<TDbTable> context;

               var mapper = new MapperConfiguration(cfg => cfg.CreateMap<TDbTable, Teacher>()).CreateMapper();
               using (var db = new TeacherContext())
               {
                    context = db.Teacher.ToList();
               }
               return mapper.Map<List<Teacher>>(context);
          }

          internal List<Enroll> getAllEnrolls(string searchCriteria)
          {
               List<EDbTable> context;

               var mapper = MappingHelper.Configure<EDbTable, Enroll>();
               using (var db = new CourseContext())
               {
                    if (!string.IsNullOrEmpty(searchCriteria))
                    {
                         if (int.TryParse(searchCriteria, out int searchInt))
                         {
                              // Search by integer if the search criteria is a valid integer
                              context = db.Enroll.Where(e => e.CourseId == searchInt).ToList();
                         }
                         else
                         {
                              // Search by string if the search criteria is not a valid integer
                              context = db.Enroll.Where(e => e.FullName.Contains(searchCriteria)).ToList();
                         }
                    }
                    else
                    {
                         context = db.Enroll.ToList();
                    }
               }
               return mapper.Map<List<Enroll>>(context);
          }
          //AddNewEntity
          internal ULoginResp AddNewCourse(Course data)
          {
               
               IMapper mapper = new MapperConfiguration(cfg => cfg.CreateMap<Course, CDbTable>()).CreateMapper();
               var context = mapper.Map<CDbTable>(data);

               using (var db = new CourseContext())
               {
                    db.Courses.Add(context);
                    db.SaveChanges();
               }
               return new ULoginResp { Status = true };
          }

          internal ULoginResp AddNewTeacher(Teacher data)
          {
               IMapper mapper = new MapperConfiguration(cfg => cfg.CreateMap<Teacher, TDbTable>()).CreateMapper();
               var context = mapper.Map<TDbTable>(data);

               using (var db = new TeacherContext())
               {
                    db.Teacher.Add(context);
                    db.SaveChanges();
               }
               return new ULoginResp { Status = true };
          }

          internal ULoginResp EnrollCourse(int ticketEventId, Enroll ticketModel)
          {
               CDbTable eventEF;
               using (var db = new CourseContext())
               {
                    eventEF = db.Courses.FirstOrDefault(e => e.Id == ticketEventId);
               }
               if (eventEF == null)
               {
                    throw new ArgumentException($"The event with ID {ticketEventId} does not exist.");
               }
               
               ticketModel.TotalPrice = ticketModel.TotalPrice +  eventEF.Price;

               IMapper mapper = MappingHelper.Configure<Enroll, EDbTable>();
               var ticketEF = mapper.Map<EDbTable>(ticketModel);

               using (var db = new CourseContext())
               {
                    
                    db.Enroll.Add(ticketEF);
                    db.Entry(eventEF).State = EntityState.Modified;
                    db.SaveChanges();
               }

               return new ULoginResp() { Status = true };
          }

          //GetbyID
          internal Course GetCourse(int id)
          {
               CDbTable context;
               using (var db = new CourseContext())
                    context = db.Courses.FirstOrDefault(u => u.Id == id);
               IMapper mapper = new MapperConfiguration(cfg => cfg.CreateMap<CDbTable, Course>()).CreateMapper();

               return context != null ? mapper.Map<Course>(context) : null;
          }
          internal Teacher GetTeacher(int id)
          {
               TDbTable context;
               using (var db = new TeacherContext())
                    context = db.Teacher.FirstOrDefault(u => u.Id == id);
               IMapper mapper = new MapperConfiguration(cfg => cfg.CreateMap<TDbTable, Teacher>()).CreateMapper();

               return context != null ? mapper.Map<Teacher>(context) : null;
          }

          internal Enroll GetEnrollById(int id)
          {
               EDbTable context;
               using (var db = new CourseContext())
                    context = db.Enroll.FirstOrDefault(u => u.Id == id);
               IMapper mapper = MappingHelper.Configure<EDbTable, Enroll>();

               return context != null ? mapper.Map<Enroll>(context) : null;
          }
          internal List<Enroll> GetTicketUserById(int userId, int? eventId)
          {
               List<EDbTable> context;
               using (var db = new CourseContext())
               {
                    if (eventId.HasValue)
                    {
                         context = db.Enroll.Where(t => (t.UserId == userId && t.CourseId == eventId)).ToList();
                    }
                    else
                    {
                         context = db.Enroll.Where(b => b.UserId == userId).ToList();
                    }
               }
               var mapper = MappingHelper.Configure<EDbTable, Enroll>();
               return mapper.Map<List<Enroll>>(context);
          }

          //Update
          internal ULoginResp Update(Course data)
          {
               if (GetCourse(data.Id) == null)
                    return new ULoginResp { Status = false, StatusMsg = "An Error occur at updating" };

               IMapper mapper = new MapperConfiguration(cfg => cfg.CreateMap<Course, CDbTable>()).CreateMapper();
               var result = mapper.Map<CDbTable>(data);

               using (var db = new CourseContext())
               {
                    db.Courses.AddOrUpdate(result);
                    db.SaveChanges();
               }
               return new ULoginResp { Status = true };

          }
          internal ULoginResp UpdateTea(Teacher data)
          {
               if (GetTeacher(data.Id) == null)
                    return new ULoginResp { Status = false, StatusMsg = "An Error occur at updating" };

               IMapper mapper = new MapperConfiguration(cfg => cfg.CreateMap<Teacher, TDbTable>()).CreateMapper();
               var result = mapper.Map<TDbTable>(data);

               using (var db = new TeacherContext())
               {
                    db.Teacher.AddOrUpdate(result);
                    db.SaveChanges();
               }
               return new ULoginResp { Status = true };

          }
          //Delete
          internal void DeleteCourse(int id)
          {
               using (var db = new CourseContext())
               {
                    var course = db.Courses.FirstOrDefault(u => u.Id == id);
                    if (course != null)
                    {
                         db.Courses.Remove(course);
                         db.SaveChanges();
                    }
               }
          }
          internal void DeleteProfessor(int id)
          {
               using (var db = new TeacherContext())
               {
                    var teacher = db.Teacher.FirstOrDefault(u => u.Id == id);
                    if (teacher != null)
                    {
                         db.Teacher.Remove(teacher);
                         db.SaveChanges();
                    }
               }
          }

          internal void DeleteEnroll(int id)
          {
               using (var db = new CourseContext())
               {
                    var booking = db.Enroll.FirstOrDefault(p => p.Id == id);
                    var bEvent = db.Courses.FirstOrDefault(e => e.Id == booking.CourseId);
                    if (booking == null) return;
                    //if (bEvent != null)
                    //{
                    //     bEvent.TicketsLeft += booking.Quantity;
                    //     db.Entry(bEvent).State = EntityState.Modified;
                    //}
                    db.Enroll.Remove(booking);
                    db.SaveChanges();
               }
          }

     }


}
