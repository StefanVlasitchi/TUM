using System.Web;
using System.Web.Mvc;
using System.Web.Routing;
using Lernify.BusinessLogic.Interfaces;
using Lernify.Domain.Enums;
using Lernify.Web.Extension;

namespace Lernify.Web.Filters
{
     public class AuthenticatedAttribute : ActionFilterAttribute
     {
          private readonly ISession _session;
          public AuthenticatedAttribute()
          {
               var bl = new BusinessLogic.BusinessLogic();
               _session = bl.GetSessionBL();
          }
          public override void OnActionExecuting(ActionExecutingContext filterContext)
          {
               var userSession = System.Web.HttpContext.Current.GetMySessionObject();
               if (userSession != null)
               {

                    var cookie = HttpContext.Current.Request.Cookies["X-KEY"];
                    if (cookie != null)
                    {
                         var profile = _session.GetUserByCookie(cookie.Value);
                         if (profile != null && profile.Level != URole.Visitor)
                         {
                              HttpContext.Current.Session.Add("__SessionObject", profile);
                              return;
                         }
                    }
               }
               filterContext.Result = new RedirectToRouteResult(
                    new RouteValueDictionary(new { controller = "Error", action = "Error404" }));
          }
     }
}