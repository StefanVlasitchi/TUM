using System.Collections.Generic;
using Lernify.BusinessLogic.Core;
using Lernify.BusinessLogic.Interfaces;
using Lernify.Domain.Entities.Teacher;
using Lernify.Domain.Entities.User;

namespace Lernify.BusinessLogic.Implementation
{
     public class TeacherBL: ProductApi, ITeacher
     {
          public List<Teacher> GetTeacher()
          {
               return GetTeacherList();
          }

          public ULoginResp AddTeacher(Teacher data)
          {
               return AddNewTeacher(data);
          }

          public Teacher GetTeacherById(int id)
          {
               return GetTeacher(id);
          }

          public ULoginResp UpdateTeacher(Teacher data)
          {
               return UpdateTea(data);//Nume la fel ca la Course
          }

          public void DeleteTeacher(int id)
          {
               DeleteProfessor(id);
          }

     }
}