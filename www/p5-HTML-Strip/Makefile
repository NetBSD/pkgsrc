# $NetBSD: Makefile,v 1.5 2010/08/21 16:36:49 seb Exp $

DISTNAME=	HTML-Strip-1.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-Strip/
COMMENT=	Perl5 module for strip HTML tag

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/HTML/Strip/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
