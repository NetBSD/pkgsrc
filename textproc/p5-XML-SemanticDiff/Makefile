# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:51 joerg Exp $
#

DISTNAME=	XML-SemanticDiff-0.95
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-SemanticDiff/
COMMENT=	Perl extension for comparing XML documents

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Digest-MD5-[0-9]*:../../security/p5-Digest-MD5
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

PERL5_PACKLIST=	auto/XML/SemanticDiff/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
