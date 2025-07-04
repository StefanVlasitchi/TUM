﻿using Lernify.Domain.Enums;
using System;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;


namespace Lernify.Domain.Entities.User
{
     public class UDbTable

     {
          [Key]
          [DatabaseGenerated(DatabaseGeneratedOption.Identity)]

          public int Id { get; set; }


          [Required]
          [Display(Name = " Username")]
          [StringLength(30, MinimumLength = 5, ErrorMessage = " Username cannot be longer than 30 seconds. ")]

          public string Username { get; set; }

          [Required]
          [Display(Name = " Password")]
          [StringLength(50, MinimumLength = 8, ErrorMessage = "Password cannot be shorter than 8 characters. ")]

          public string Password { get; set; }

          [Required]
          [Display(Name = "Email Address")]
          [StringLength(30)]
          public string Email { get; set; }

          [DataType(DataType.Date)]
          public DateTime LastLogin { get; set; }

          [StringLength(30)]
          public string LasIp { get; set; }

          public URole Level { get; set; }

     }
}