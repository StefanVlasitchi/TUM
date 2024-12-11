using System.Collections.Generic;
using Lernify.BusinessLogic.Core;
using Lernify.BusinessLogic.Interfaces;
using Lernify.Domain.Entities.Course;
using Lernify.Domain.Entities.User;

namespace Lernify.BusinessLogic.Implementation
{
     public class CourseBL : ProductApi, ICourse
     {
          public List<Course> GetList()
          {
               return GetCourseList();
          }

          public Course GetbyId(int id)
          {
               return GetCourse(id);
          }

          public ULoginResp Add(Course course)

          {
               return AddNewCourse(course);
          }

          public ULoginResp Edit(Course course)

          {
               return Update(course);
          }

          public void Delete(int id)

          {
                DeleteCourse(id);
          }


     }
}