using System.Web.Optimization;

namespace Learnify.Web.Controllers
{
     public static class BundleConfig
     {
          public static void RegisterBundles(BundleCollection bundles)
          {
               bundles.Add(new StyleBundle("~/bundles/animation/css").Include(
                    "~/assets/css/vendor/animation.min.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/bootstrap/css").Include(
                    "~/assets/css/vendor/bootstrap.min.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/icomoon/css").Include(
                    "~/assets/css/vendor/icomoon.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/jqueru-ui/css").Include(
                    "~/assets/css/vendor/jqueru-ui-min.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/lightbox/css").Include(
                    "~/assets/css/vendor/lightbox.min.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/magnifypopup/css").Include(
                    "~/assets/css/vendor/magnifypopup.min.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/odometer/css").Include(
                    "~/assets/css/vendor/odometer.min.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/remixicon/css").Include(
                    "~/assets/css/vendor/remixicon.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/swiper-bundle/css").Include(
                    "~/assets/css/vendor/swiper-bundle.min.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/tipped/css").Include(
                    "~/assets/css/vendor/tipped.min.css", new CssRewriteUrlTransform()));
               bundles.Add(new StyleBundle("~/bundles/app/css").Include(
                    "~/assets/css/app.css", new CssRewriteUrlTransform()));


               bundles.Add(new ScriptBundle("~/bundles/backtotop/js").Include(
                 "~/assets/js/vendor/backtotop.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/bootstrap/h=js").Include(
                   "~/assets/js/vendor/bootstrap.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/imageloaded/js").Include(
                   "~/assets/js/vendor/imageloaded.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/isotop/js").Include(
                   "~/assets/js/vendor/isotop.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/jquery-ui/js").Include(
                   "~/assets/js/vendor/jquery-ui.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/jquery.countdown/js").Include(
                   "~/assets/js/vendor/jquery.countdown.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/isInViewport.jquery/js").Include(
                   "~/assets/js/vendor/isInViewport.jquery.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/lightbox/js").Include(
                   "~/assets/js/vendor/lightbox.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/magnifypopup/js").Include(
                   "~/assets/js/vendor/magnifypopup.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/modernizr/js").Include(
                   "~/assets/js/vendor/modernizr.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/odometer/js").Include(
                   "~/assets/js/vendor/odometer.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/paralax-scroll/js").Include(
                   "~/assets/js/vendor/paralax-scroll.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/paralax/js").Include(
                   "~/assets/js/vendor/paralax.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/sal/js").Include(
                   "~/assets/js/vendor/sal.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/smooth-scroll/js").Include(
                   "~/assets/js/vendor/smooth-scroll.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/svg-inject.min/js").Include(
                   "~/assets/js/vendor/svg-inject.min.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/swiper-bundle/js").Include(
                   "~/assets/js/vendor/swiper-bundle.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/tipped/js").Include(
                   "~/assets/js/vendor/tipped.min.js", new CssRewriteUrlTransform()));
               bundles.Add(new ScriptBundle("~/bundles/vivus/js").Include(
                   "~/assets/js/vendor/vivus.min.js", new CssRewriteUrlTransform()));
               /*bundles.Add(new ScriptBundle("~/bundles/app/js").Include(
                   "~/assets/js/app.js", new CssRewriteUrlTransform()));*/
               bundles.Add(new ScriptBundle("~/bundles/jquery/js").Include(
                    "~/assets/js/vendor/jquery.min.js", new CssRewriteUrlTransform()));
          }
          
     }

}