# $NetBSD: Makefile,v 1.15 2019/06/30 20:17:34 nia Exp $
#

DISTNAME=	HTTP-GHTTP-1.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-GHTTP
COMMENT=	Perl interface to the gnome ghttp library

PERL5_PACKLIST= auto/HTTP/GHTTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/libghttp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
