# $NetBSD: Makefile,v 1.11 2004/01/05 22:16:25 jlam Exp $
#

DISTNAME=		HTML-Tagset-3.03
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5htg
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=		jlam@NetBSD.org
COMMENT=		Perl5 module of data tables useful in parsing HTML

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Tagset/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
