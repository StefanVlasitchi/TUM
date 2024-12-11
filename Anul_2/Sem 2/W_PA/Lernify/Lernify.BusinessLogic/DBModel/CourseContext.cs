using Lernify.Domain.Entities.User;
using System.Data.Entity;
using Lernify.Domain.Entities.Course;
using Lernify.Domain.Entities.Enroll;

namespace Lernify.BusinessLogic.DBModel
{
     public class CourseContext:DbContext
     {
          public CourseContext() :
               base("name=Lernify") // connectionstring name define in your web.config
          {

          }

          public virtual DbSet<CDbTable> Courses { get; set; }
          public virtual DbSet<EDbTable> Enroll { get; set; }
     }
}