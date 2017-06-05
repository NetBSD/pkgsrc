# $NetBSD: Makefile,v 1.5 2017/06/05 14:25:29 ryoon Exp $

DISTNAME=	Plack-Middleware-RemoveRedundantBody-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Plack/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Plack-Middleware-ReverseProxy/
COMMENT=	Removes body for HTTP response if it's not required
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Plack/Middleware/RemoveRedundantBody/.packlist

DEPENDS+=	p5-Plack>=0:../../www/p5-Plack
#DEPENDS+=	{perl>=5.10.1,p5-parent-[0-9]*}:../../devel/p5-parent

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
