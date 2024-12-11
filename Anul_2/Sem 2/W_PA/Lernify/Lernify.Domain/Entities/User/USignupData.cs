using System;
using Lernify.Domain.Enums;

namespace Lernify.Domain.Entities.User
{
     public class USignupData
     {
          public string Email { get; set; }
          public string Username { get; set; }
          public string Password { get; set; }
          public string  ConfirmPassword { get; set; }
          public string LoginIp { get; set; }
          public URole Level { get; set; }
          public DateTime LoginDateTime { get; set; }
     }
}