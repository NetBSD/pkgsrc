# $NetBSD: Makefile,v 1.5 2012/10/03 21:58:56 wiz Exp $

DISTNAME=	Plack-Middleware-ConsoleLogger-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Plack-Middleware-ConsoleLogger/
COMMENT=	Plack middleware to write logs to Firebug or Webkit Inspector
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Plack/Middleware/ConsoleLogger/.packlist

BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
DEPENDS+=	p5-Plack>=0.99:../../www/p5-Plack
DEPENDS+=	p5-parent-[0-9]*:../../devel/p5-parent
DEPENDS+=	p5-JavaScript-Value-Escape-[0-9]*:../../www/p5-JavaScript-Value-Escape

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
