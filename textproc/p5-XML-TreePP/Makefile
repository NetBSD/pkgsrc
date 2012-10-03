# $NetBSD: Makefile,v 1.5 2012/10/03 21:58:13 wiz Exp $

DISTNAME=	XML-TreePP-0.41
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
