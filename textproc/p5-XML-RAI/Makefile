# $NetBSD: Makefile,v 1.1.1.1 2004/06/20 22:28:00 schmonz Exp $

DISTNAME=	XML-RAI-0.51
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	schmonz@NetBSD.org
COMMENT=	Maps RSS tags to one common simplified interface

DEPENDS+=	p5-XML-RSS-Parser>=2.15:../../textproc/p5-XML-RSS-Parser
DEPENDS+=	p5-TimeDate>=1.14:../../time/p5-TimeDate

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/RAI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
