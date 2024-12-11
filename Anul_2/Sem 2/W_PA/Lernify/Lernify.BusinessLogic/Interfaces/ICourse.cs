using Lernify.Domain.Entities.Course;
using System.Collections.Generic;
using System;
using Lernify.Domain.Entities.User;

namespace Lernify.BusinessLogic.Interfaces
{
     public interface ICourse
     {
          List<Course> GetList();


           Course GetbyId(int id);


           ULoginResp Add(Course course);


           ULoginResp Edit(Course course);


           void Delete(int id);
     }
}