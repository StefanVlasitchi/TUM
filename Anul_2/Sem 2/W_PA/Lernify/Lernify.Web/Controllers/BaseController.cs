﻿using Lernify.BusinessLogic.Interfaces;
using Lernify.Domain.Entities.User;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using Lernify.Web.Extension;

namespace Lernify.Web.Controllers
{
     public class BaseController : Controller
     {
          private readonly ISession _session;

          public BaseController()
          {
               var bl = new BusinessLogic.BusinessLogic();
               _session = bl.GetSessionBL();
          }

          public void SessionStatus()
          {
               UserMinimal user = new UserMinimal
               {
                    Username = "Guest",
                    Email = "",
                    Level = 0
               };
               var apiCookie = Request.Cookies["X-KEY"];
               if (apiCookie != null)
               {
                    var profile = _session.GetUserByCookie(apiCookie.Value);
                    if (profile != null)
                    {
                         System.Web.HttpContext.Current.SetMySessionObject(profile);
                         System.Web.HttpContext.Current.Session["LoginStatus"] = "login";
                         user = System.Web.HttpContext.Current.GetMySessionObject();
                         ViewBag.CurrentUser = user;
                    }
                    else
                    {
                         System.Web.HttpContext.Current.Session.Clear();
                         if (ControllerContext.HttpContext.Request.Cookies.AllKeys.Contains("X-KEY"))
                         {
                              var cookie = ControllerContext.HttpContext.Request.Cookies["X-KEY"];
                              if (cookie != null)
                              {
                                   cookie.Expires = DateTime.Now.AddDays(-1);
                                   ControllerContext.HttpContext.Response.Cookies.Add(cookie);
                              }
                         }

                         System.Web.HttpContext.Current.Session["LoginStatus"] = "logout";
                         ViewBag.CurrentUser = user;
                    }
               }
               else
               {
                    System.Web.HttpContext.Current.Session["LoginStatus"] = "logout";
                    ViewBag.CurrentUser = user;
               }
          }
     }
}