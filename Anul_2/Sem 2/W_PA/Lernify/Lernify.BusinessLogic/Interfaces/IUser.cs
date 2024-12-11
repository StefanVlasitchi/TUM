using Lernify.Domain.Entities.User;
using System.Collections.Generic;

namespace Lernify.BusinessLogic.Interfaces
{
     public interface IUser
          {
               List<UserMinimal> GetList();
               UserMinimal GetById(int id);
               void Delete(int id);
          }
}
