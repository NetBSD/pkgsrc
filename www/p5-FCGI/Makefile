# $NetBSD: Makefile,v 1.25 2010/02/18 09:02:29 sno Exp $
#

DISTNAME=	FCGI-0.69
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	3
SVR4_PKGNAME=	p5fcg
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fastcgi.com/
COMMENT=	Perl5 library for FastCGI, a fast startup alternative to CGI

USE_LANGUAGES+=		c
PKG_DESTDIR_SUPPORT=	user-destdir
PERL5_PACKLIST=		auto/FCGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
