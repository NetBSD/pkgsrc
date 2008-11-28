# $NetBSD: Makefile,v 1.9 2008/11/28 14:39:59 he Exp $

DISTNAME=	XML-SAX-Writer-0.52
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-SAX-Writer/
COMMENT=	SAX2 (XML) Writer

DEPENDS+=	p5-Text-Iconv>=1.2:../../converters/p5-Text-Iconv
DEPENDS+=	p5-XML-SAX-Base>=1.01:../../textproc/p5-XML-SAX-Base
DEPENDS+=	p5-XML-NamespaceSupport>=1.00:../../textproc/p5-XML-NamespaceSupport
DEPENDS+=	p5-XML-Filter-BufferText>=1.00:../../textproc/p5-XML-Filter-BufferText

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/XML/SAX/Writer/.packlist
MAKE_ENV+=		PERL5LIB="${PREFIX}/${PERL5_SUB_INSTALLSITELIB}"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
