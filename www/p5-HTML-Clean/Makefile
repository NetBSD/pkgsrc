# $NetBSD: Makefile,v 1.9 2004/12/20 11:31:13 grant Exp $

DISTNAME=	HTML-Clean-0.8
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hcl
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module that cleans up HTML code for web browsers

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Clean/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
