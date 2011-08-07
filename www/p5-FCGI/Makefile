# $NetBSD: Makefile,v 1.28 2011/08/07 22:26:06 abs Exp $
#

DISTNAME=	FCGI-0.73
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fcg
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fastcgi.com/
COMMENT=	Perl5 library for FastCGI, a fast startup alternative to CGI

USE_LANGUAGES=		c
PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_PACKLIST=		auto/FCGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
