using System.Data.Entity;
using Lernify.Domain.Entities.Teacher;

namespace Lernify.BusinessLogic.DBModel
{
     public class TeacherContext : DbContext
     {
          public TeacherContext() : base("name=Lernify")
               
          {

          }

          public virtual DbSet<TDbTable> Teacher { get; set; }
     }

}