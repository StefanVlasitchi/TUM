using Lernify.Domain.Enums;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Lernify.Web.Models
{
     public class TeacherModel
     {

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
          public TRole Role { get; set; }
          public string Description { get; set; }
     }
}