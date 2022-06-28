# $NetBSD: Makefile,v 1.17 2022/06/28 11:36:43 wiz Exp $

DISTNAME=	XML-Parser-Lite-Tree-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Parser
COMMENT=	Perl extension for a lightweight XML tree builder
LICENSE=	(${PERL5_LICENSE}) AND artistic-2.0

PERL5_PACKLIST=		auto/XML/Parser/Lite/Tree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
