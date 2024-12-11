using System.ComponentModel.DataAnnotations;
using System.Xml.Linq;

namespace Lernify.Web.Models
{
     public class EnrollModel
     {
          public int Id { get; set; }
          public int UserId { get; set; }

          public string CourseName { get; set; }

          [Required(ErrorMessage = "Please enter your full name.")]
          [StringLength(100, ErrorMessage = "The {0} must be at least {2} characters long.", MinimumLength = 3)]
          [Display(Name = "Full Name")]
          public string FullName { get; set; }

          [Required(ErrorMessage = "Please enter your email address.")]
          [EmailAddress(ErrorMessage = "Please enter a valid email address.")]
          [Display(Name = "Email")]
          public string Email { get; set; }

          public double TotalPrice { get; set; }
          public int CourseId { get; set; }

     }
}