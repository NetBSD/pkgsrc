# $NetBSD: Makefile,v 1.29 2010/02/17 14:56:05 tnn Exp $

DISTNAME=	XML-SAX-0.96
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-SAX/
COMMENT=	Perl interface to the SAX2 XML Parser

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	p5-XML-SAX-Base-[0-9]*

DEPENDS+=	p5-XML-NamespaceSupport>=0.03:../../textproc/p5-XML-NamespaceSupport
# included in perl>=5.6.1
#DEPENDS+=	p5-File-Temp-[0-9]*:../../devel/p5-File-Temp

SUPERSEDES=	p5-XML-SAX-Base-[0-9]*

MAKE_ENV=	SKIP_SAX_INSTALL=yes
EGSUBDIR=	share/examples/p5-XML-SAX
CONF_FILES=	${EGSUBDIR}/ParserDetails.ini \
			${PERL5_INSTALLVENDORLIB}/XML/SAX/ParserDetails.ini

PERL5_PACKLIST=	auto/XML/SAX/.packlist

INSTALLATION_DIRS+=	${EGSUBDIR}

post-extract:
	${FIND} ${WRKSRC} -name "*.orig" -type f | ${XARGS} ${RM}

post-install:
	${ECHO} > ${DESTDIR:Q}${PREFIX:Q}/${EGSUBDIR}/ParserDetails.ini

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
