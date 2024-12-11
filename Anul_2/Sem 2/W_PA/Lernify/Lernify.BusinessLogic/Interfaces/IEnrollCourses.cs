using System.Collections.Generic;
using Lernify.Domain.Entities.Enroll;
using Lernify.Domain.Entities.User;

namespace Lernify.BusinessLogic.Interfaces
{
     public interface IEnrollCourses
     {
          ULoginResp Book(int enrollCourseID, Enroll enroll);
          List<Enroll> GetEnroledCourseList(string searchCriteria);
          Enroll GetById(int id);
          List<Enroll> GetByUserId(int userId, int? eventId);
          void Delete(int id);
     }
}