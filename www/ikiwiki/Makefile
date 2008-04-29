# $NetBSD: Makefile,v 1.12 2008/04/29 00:05:41 reed Exp $
#

DISTNAME=	ikiwiki_2.44
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	www textproc
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/i/ikiwiki/}

MAINTAINER=	reed@NetBSD.org
HOMEPAGE=	http://ikiwiki.info/
COMMENT=	Wiki compiler

PKG_OPTIONS_VAR=	PKG_OPTIONS.ikiwiki
PKG_SUPPORTED_OPTIONS=	imagemagick svn w3m
PKG_SUGGESTED_OPTIONS=	# none on by default

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

# http://ikiwiki.info/install/index.html
# needed dependencies:
DEPENDS+=	p5-Text-Markdown-[0-9]*:../../textproc/p5-Text-Markdown
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Template-[0-9]*:../../www/p5-HTML-Template
# used if available:
DEPENDS+=	p5-CGI-Session-[0-9]*:../../www/p5-CGI-Session
DEPENDS+=	p5-CGI-FormBuilder>=3.05:../../www/p5-CGI-FormBuilder
DEPENDS+=	p5-Mail-Sendmail-[0-9]*:../../mail/p5-Mail-Sendmail
DEPENDS+=	p5-Time-Duration-[0-9]*:../../time/p5-Time-Duration
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=	p5-HTML-Scrubber>=0.08:../../www/p5-HTML-Scrubber
DEPENDS+=	p5-RPC-XML-[0-9]*:../../net/p5-RPC-XML
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
DEPENDS+=	p5-XML-Feed-[0-9]*:../../textproc/p5-XML-Feed
DEPENDS+=	p5-File-MimeInfo-[0-9]*:../../devel/p5-File-MimeInfo
DEPENDS+=	p5-gettext-[0-9]*:../../devel/p5-gettext

# for img plugin
.if !empty(PKG_OPTIONS:Mimagemagick)
# the plugin uses the ImageMagick tools via PerlMagic
DEPENDS+=	p5-PerlMagick-[0-9]*:../../graphics/p5-PerlMagick
.endif

.if !empty(PKG_OPTIONS:Msvn)
DEPENDS+=	subversion-base-[0-9]*:../../devel/subversion-base
.endif

PLIST_VARS+=	w3m
.if !empty(PKG_OPTIONS:Mw3m)
DEPENDS+=	w3m-[0-9]*:../../www/w3m
PLIST.w3m=	yes
SUBST_SED.makefile+=	-e 's,/lib/w3m/cgi-bin,/libexec/w3m/cgi-bin,'
INSTALLATION_DIRS+=	share/doc/ikiwiki/w3mmode
.else
SUBST_SED.makefile+=	-e 's,^\(.*install .*/lib/w3m/cgi-bin\),\#\1,'
.endif

INSTALLATION_DIRS+=	share/doc/ikiwiki
WRKSRC=		${WRKDIR}/ikiwiki
PERL5_PACKLIST=	auto/IkiWiki/.packlist
USE_LANGUAGES=	# none
USE_TOOLS=	gmake perl:run xgettext

# TODO: check these
REPLACE_PERL+=	IkiWiki.pm ikiwiki-w3m.cgi mdwn2man pm_filter
REPLACE_PERL+=	ikiwiki.in ikiwiki-mass-rebuild ikiwiki-update-wikilist
REPLACE_PERL+=	ikiwiki-transition
REPLACE_PERL+=	t/*.t IkiWiki/*.pm IkiWiki/*/*.pm
REPLACE_PERL+=	doc/ikiwiki.setup doc/w3mmode/ikiwiki.setup
#REPLACE_PERL+=	plugins/externaldemo	# not installed anymore

# not installed anymore
#REPLACE_PYTHON+=	plugins/rst
# TODO: add an rst option
# rst plugin (reStructuredText) needs the python-docutils module
#CHECK_INTERPRETER_SKIP+=	lib/ikiwiki/plugins/rst

SUBST_CLASSES+=	makefile
SUBST_STAGE.makefile=	post-patch
SUBST_FILES.makefile=	Makefile.PL
SUBST_SED.makefile+=	-e 's,share/man/man,${PKGMANDIR}/man,g'

post-install:
	${INSTALL_DATA} ${WRKSRC}/html/ikiwiki.setup \
		${PREFIX}/share/doc/ikiwiki/
.if !empty(PKG_OPTIONS:Mw3m)
	${INSTALL_DATA} ${WRKSRC}/html/w3mmode.html \
		${PREFIX}/share/doc/ikiwiki/
	${INSTALL_DATA} ${WRKSRC}/doc/w3mmode/ikiwiki.setup \
		${PREFIX}/share/doc/ikiwiki/w3mmode/ikiwiki.setup
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
