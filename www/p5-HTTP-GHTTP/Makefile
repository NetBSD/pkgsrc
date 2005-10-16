# $NetBSD: Makefile,v 1.1.1.1 2005/10/16 05:01:06 minskim Exp $
#

DISTNAME=	HTTP-GHTTP-1.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-GHTTP/
COMMENT=	Perl interface to the gnome ghttp library

PERL5_PACKLIST= auto/HTTP/GHTTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/libghttp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
