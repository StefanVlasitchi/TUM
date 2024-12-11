using System.ComponentModel.DataAnnotations;

namespace Lernify.Web.Models
{
     public class ReviewModel
     {
         
               [Required]
               public string Name { get; set; } //defacto o sa citeasca numele de utilizator.
               [Required]
               public string Email { get; set; }// datele utilizatorului logat 
               [Required]
               [StringLength(30, MinimumLength = 8)]
               public string Title { get; set; }
               [Required]
               [StringLength(500, MinimumLength = 30)]
               public string Message { get; set; }

          
     }
}