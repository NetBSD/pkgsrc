# $NetBSD: Makefile,v 1.6 2011/08/14 16:05:57 obache Exp $
#

DISTNAME=	HTTP-GHTTP-1.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-GHTTP/
COMMENT=	Perl interface to the gnome ghttp library

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST= auto/HTTP/GHTTP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/libghttp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
