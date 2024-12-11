using Learnify.BusinessLogic.Core;
using Learnify.BusinessLogic.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Learnify.Domain.Entities.User;

namespace Learnify.BusinessLogic
{
     public class SessionBL : UserApi, ISession
     {
          public ULoginResp UserLogin(ULoginData data)
          {
               throw new NotImplementedException();
          }

     }
}