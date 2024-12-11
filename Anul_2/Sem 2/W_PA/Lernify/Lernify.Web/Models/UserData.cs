using System.Collections.Generic;
using Lernify.Domain.Enums;
using System.Web;
using System.Linq;
using System;

namespace Lernify.Web.Models
{
     public class UserData
     {
          public int Id { get; set; }
          public string Username { get; set; }
          public string Email { get; set; }
          public DateTime LastLogin { get; set; }
          public string LasIp { get; set; }
          public URole Level { get; set; }


     }
}