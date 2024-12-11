using System.ComponentModel.DataAnnotations;
using Lernify.Domain.Enums;

namespace Lernify.Domain.Entities.Teacher
{
     public class TDbTable
     {
          [Key]
          [Required]
          public int Id { get; set; }
          [Required]
          public string FirstName { get; set; } //
          [Required]
          public string LastName { get; set; }
          [Required]
          public string ImageUrl { get; set; } //
          [Required]
          public string Mail { get; set; }

          [Required]
          public  TRole Role { get; set; }

          public string Description { get; set; }

     }
}