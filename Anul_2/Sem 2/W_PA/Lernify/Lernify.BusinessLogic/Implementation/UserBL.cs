using Lernify.BusinessLogic.Core;
using Lernify.BusinessLogic.Interfaces;
using Lernify.Domain.Entities.User;
using System.Collections.Generic;

namespace Lernify.BusinessLogic.Implementation
{
     public class UserBL : AdminApics, IUser
     {
          public List<UserMinimal> GetList()
          {
               return GetUsers();
          }

          public UserMinimal GetById(int id)
          {
               return GetUserById(id);
          }
          public void Delete(int id)
          {
               DeleteUser(id);
          }
     }
}