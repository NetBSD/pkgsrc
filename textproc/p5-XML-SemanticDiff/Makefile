# $NetBSD: Makefile,v 1.22 2019/06/30 20:17:10 nia Exp $

DISTNAME=	XML-SemanticDiff-1.0007
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-SemanticDiff
COMMENT=	Perl extension for comparing XML documents
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

PERL5_PACKLIST=	auto/XML/SemanticDiff/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
