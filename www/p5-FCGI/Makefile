# $NetBSD: Makefile,v 1.22 2008/06/20 01:09:42 joerg Exp $
#

PKGVER=			0.67
DISTNAME=	FCGI-${PKGVER}
PKGNAME=	p5-FCGI-${PKGVER}
SVR4_PKGNAME=		p5fcg
PKGREVISION=		2
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.fastcgi.com/
COMMENT=		Perl5 library for FastCGI, a fast startup alternative to CGI

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/FCGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
