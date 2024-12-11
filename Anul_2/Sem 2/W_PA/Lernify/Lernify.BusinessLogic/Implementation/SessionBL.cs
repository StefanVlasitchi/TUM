using System.Web;
using Lernify.BusinessLogic.Core;
using Lernify.BusinessLogic.Interfaces;
using Lernify.Domain.Entities.User;

namespace Lernify.BusinessLogic.Implementation
{
     public class SessionBL : UserApi, ISession
     {
          public ULoginResp UserLogin(ULoginData data)
          {
               return UserLoginAction(data);
          }

          public ULoginResp UserRegister(USignupData data)
          {
               return UserRegisterAction(data);

          }
          public HttpCookie GenCookie(string loginCredential)
          {
               return Cookie(loginCredential);
          }

          public UserMinimal GetUserByCookie(string apiCookieValue)
          {
               return UserCookie(apiCookieValue);
          }
     };
}
