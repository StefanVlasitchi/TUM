using System.Collections.Generic;
using Lernify.Domain.Entities.Course;
using Lernify.Domain.Entities.Teacher;
using Lernify.Domain.Entities.User;

namespace Lernify.BusinessLogic.Interfaces
{
     public interface ITeacher
     {
          List<Teacher> GetTeacher();
          ULoginResp AddTeacher(Teacher data);
          Teacher GetTeacherById(int id);
          ULoginResp UpdateTeacher(Teacher data);
          void DeleteTeacher(int id);

     }
}