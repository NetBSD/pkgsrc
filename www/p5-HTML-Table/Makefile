# $NetBSD: Makefile,v 1.17 2006/03/04 21:31:02 jlam Exp $

DISTNAME=		HTML-Table-2.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5htb
PKGREVISION=		2
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/HTML-Table/
COMMENT=		Perl5 module to simplify creating HTML tables

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/HTML/Table/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
