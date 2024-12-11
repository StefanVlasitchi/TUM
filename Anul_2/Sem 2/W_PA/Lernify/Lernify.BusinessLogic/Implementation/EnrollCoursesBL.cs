using Lernify.BusinessLogic.Core;
using Lernify.BusinessLogic.Interfaces;
using System.Collections.Generic;
using Lernify.Domain.Entities.Enroll;
using Lernify.Domain.Entities.User;

namespace Lernify.BusinessLogic.Implementation
{
     public class EnrollCoursesBL: ProductApi, IEnrollCourses

     {
          public ULoginResp Book(int enrollCourseId, Enroll enroll)
          {
               return EnrollCourse(enrollCourseId, enroll);
          }

          //Read
          public List<Enroll> GetEnroledCourseList(string searchCriteria)
          {
               return getAllEnrolls(searchCriteria);
          }

          public Enroll GetById(int id)
          {
               return GetEnrollById(id);
          }
          public List<Enroll> GetByUserId(int userId, int? eventId)
          {
               return GetTicketUserById(userId, eventId);
          }

          //Delete
          public void Delete(int id)
          {
               DeleteEnroll(id);
          }
     }
}
