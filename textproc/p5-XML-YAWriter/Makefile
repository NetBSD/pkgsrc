# $NetBSD: Makefile,v 1.6 2004/04/22 06:08:27 minskim Exp $
#

DISTNAME=	XML-Handler-YAWriter-0.23
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xhy
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Another Perl module for writing XML documents

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/Handler/YAWriter/.packlist
REPLACE_PERL=		xmlpretty

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
