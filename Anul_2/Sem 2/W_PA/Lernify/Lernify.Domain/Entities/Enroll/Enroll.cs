using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lernify.Domain.Entities.Enroll
{
     public class Enroll
     {
          public int Id { get; set; }
          public int UserId { get; set; }
          public string CourseName { get; set; }
          public string FullName { get; set; }
          public string Email { get; set; }
          public double TotalPrice { get; set; }
          public int CourseId { get; set; }
     }
}
