# $NetBSD: Makefile,v 1.14 2018/08/22 09:47:42 wiz Exp $
#

DISTNAME=	HTTP-GHTTP-1.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-GHTTP/
COMMENT=	Perl interface to the gnome ghttp library

PERL5_PACKLIST= auto/HTTP/GHTTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/libghttp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
