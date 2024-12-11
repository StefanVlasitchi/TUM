﻿using Lernify.Domain.Enums;
using System.ComponentModel.DataAnnotations;
using System.Xml.Linq;

namespace Lernify.Web.Models
{
     public class UserRegister
     {
          
               [Required]
               [Display(Name = "Username")]
               [StringLength(30, MinimumLength = 5, ErrorMessage = "Username cannot be less than 5 or longer than 30 characters.")]
               public string Username { get; set; }

               [Required]
               [Display(Name = "Password")]
               [StringLength(50, MinimumLength = 8, ErrorMessage = "Password cannot be shorter than 8 characters.")]
               [DataType(DataType.Password)]
               public string Password { get; set; }

               [Required]
               [Display(Name = "Confirm Password")]
               [DataType(DataType.Password)]
               [Compare("Password", ErrorMessage = "The password and confirmation password do not match.")]
               public string ConfirmPassword { get; set; }

               [Required]
               [Display(Name = "Email Address")]
               [StringLength(30)]
               [EmailAddress(ErrorMessage = "Invalid Email Address")]
               public string Email { get; set; }

               public URole Level { get; set; }
          
     }
}