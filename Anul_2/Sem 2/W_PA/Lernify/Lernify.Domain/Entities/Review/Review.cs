using System.ComponentModel.DataAnnotations.Schema;
using System.ComponentModel.DataAnnotations;
using System;

namespace Lernify.Domain.Entities.Review
{
     public class Review
     {
             [Required]
               public int Id { get; set; }
               [Required]
               public string Name { get; set; }
               [Required]
               public string Email { get; set; }
               [Required]
               public string Title { get; set; }
               [Required]
               public string Message { get; set; }

               public DateTime Date { get; set; }
     }
}