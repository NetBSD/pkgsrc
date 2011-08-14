# $NetBSD: Makefile,v 1.3 2011/08/14 15:14:20 obache Exp $

DISTNAME=	XML-TreePP-0.39
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-TreePP/
COMMENT=	Pure Perl 5 implementation for parsing/writing XML documents
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=			# empty
PERL5_PACKLIST=			auto/XML/TreePP/.packlist
CHECK_PORTABILITY_SKIP+=	make-dist.sh

DEPENDS+=	p5-libwww>=5.802:../../www/p5-libwww

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
