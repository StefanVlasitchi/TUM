using System;
using System.Web;
using System.Web.Http;
using System.Web.Mvc;
using System.Web.Optimization;
using System.Web.Routing;
using Learnify.Web.Controllers;

namespace Learnify.Web
{
     public class Global : HttpApplication
     {
          void Application_Start(object sender, EventArgs e)
          {
               // Code that runs on application startup
               AreaRegistration.RegisterAllAreas();
               RouteConfig.RegisterRoutes(RouteTable.Routes);

               
               BundleConfig.RegisterBundles(BundleTable.Bundles);
                    
          }
     }
}