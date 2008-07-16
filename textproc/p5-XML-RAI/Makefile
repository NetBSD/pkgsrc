# $NetBSD: Makefile,v 1.10 2008/07/16 09:47:47 rhaen Exp $

DISTNAME=	XML-RAI-1.3022
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	rhaen@NetBSD.org
COMMENT=	Maps RSS tags to one common simplified interface

DEPENDS+=	p5-XML-RSS-Parser>=4.0:../../textproc/p5-XML-RSS-Parser
DEPENDS+=	p5-TimeDate>=1.14:../../time/p5-TimeDate

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/XML/RAI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
