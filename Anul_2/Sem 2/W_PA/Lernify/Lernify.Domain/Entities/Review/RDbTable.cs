using System.ComponentModel.DataAnnotations.Schema;
using System.ComponentModel.DataAnnotations;
using System;

namespace Lernify.Domain.Entities.Review
{
     public class RDbTable
     {
          [Key]
          [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
          public int Id { get; set; }
          public string Name { get; set; }
          public string Email { get; set; }
          public string Title { get; set; }
          public string Message { get; set; }
          public DateTime Date { get; set; }
     }
}