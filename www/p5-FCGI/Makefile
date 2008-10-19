# $NetBSD: Makefile,v 1.23 2008/10/19 19:19:07 he Exp $
#

PKGVER=			0.67
DISTNAME=	FCGI-${PKGVER}
PKGNAME=	p5-FCGI-${PKGVER}
PKGREVISION=		3
SVR4_PKGNAME=		p5fcg
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=FCGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.fastcgi.com/
COMMENT=		Perl5 library for FastCGI, a fast startup alternative to CGI

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/FCGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
