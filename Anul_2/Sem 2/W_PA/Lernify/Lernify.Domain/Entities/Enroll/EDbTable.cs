using System.ComponentModel.DataAnnotations.Schema;
using System.ComponentModel.DataAnnotations;

namespace Lernify.Domain.Entities.Enroll
{
     public class EDbTable
     {
          [Key]
          [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
          public int Id { get; set; }
          public int UserId { get; set; }
          public string CourseName { get; set; }
          public string FullName { get; set; }
          public string Email { get; set; }
          public double TotalPrice { get; set; }
          public int CourseId { get; set; }
     }
}